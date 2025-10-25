(function () {
  // prevent duplicate popups
  function removeExisting()
  {
    const existing = document.getElementById('ms-auth-overlay');
    if (existing)
		existing.remove();
  }

  function createEl(tag, props = {}, children = [])
  {
    const el = document.createElement(tag);
    Object.entries(props).forEach(([k, v]) => {
      if (k === 'class')
		el.className = v;
      else if (k === 'html')
		el.innerHTML = v;
      else if (k === 'style')
		Object.assign(el.style, v);
      else
		el.setAttribute(k, v);
    });
    children.forEach(c => el.appendChild(c));
    return el;
  }

  function switchTab(panel, tab)
  {
    const loginForm = panel.querySelector('#ms-login-form');
    const signupForm = panel.querySelector('#ms-signup-form');
    const resetForm = panel.querySelector('#ms-reset-form');
    const tLogin = panel.querySelector('#ms-tab-login');
    const tSignup = panel.querySelector('#ms-tab-signup');
    const isLogin = tab === 'login';
    loginForm.style.display = isLogin ? 'block' : 'none';
    signupForm.style.display = isLogin ? 'none' : 'block';
    if (resetForm)
		resetForm.style.display = 'none';
    tLogin.classList.toggle('ms-active', isLogin);
    tSignup.classList.toggle('ms-active', !isLogin);
    // focus first input
    const firstInput = (isLogin ? loginForm : signupForm).querySelector('input');
    if (firstInput)
		setTimeout(() => firstInput.focus(), 50);
  }

  async function postJSON(url, payload)
  {
    const res = await fetch(url, {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify(payload)
    });
    // try parse JSON, otherwise capture text for debugging
    let data;
    try
	{
		data = await res.json();
	}
	catch (err)
	{
		data = await res.text().catch(() => ({}));
	}
    return { ok: res.ok, status: res.status, data, url };
  }

  // try multiple endpoints in order until one returns a non-404 (useful when backend route name differs)
  async function tryPostWithFallback(urls, payload)
  {
    let last;
    for (const u of urls)
	{
      try
	  {
        const r = await postJSON(u, payload);
        last = r;
        // treat anything but 404 as a valid response to inspect
        if (r.status !== 404)
			return r;
      }
	  catch (err)
	  {
        last = { ok: false, status: 0, data: err.message || String(err), url: u };
      }
    }
    return last;
  }

  // validation helpers
  function validateEmail(email)
  {
    if (!email)
		return false;
    // simple, effective email regex
    const re = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    return re.test(String(email).toLowerCase());
  }

  function validateStrongPassword(pw)
  {
    // at least 8 chars, one lowercase, one uppercase, one digit, one special char
    const re = /^(?=.{8,}$)(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[\W_]).*$/;
    return re.test(pw);
  }

  function passwordStrengthText(pw)
  {
    if (!pw)
		return '';
    if (pw.length < 8)
		return 'Too short';
    const veryStrong = /^(?=.{12,}$)(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[\W_]).*$/;
    if (veryStrong.test(pw))
		return 'Very strong';
    if (validateStrongPassword(pw))
		return 'Strong';
    // medium: at least 8 and two of the char classes
    const medium = /^(?=.{8,}$)((?=.*[a-z])(?=.*[A-Z])|(?=.*[a-z])(?=.*\d)|(?=.*[A-Z])(?=.*\d)).*$/;
    if (medium.test(pw))
		return 'Medium';
    return 'Weak';
  }

  // exported global function used by index.html
  window.login = function () {
    removeExisting();

    // overlay
    const overlay = createEl('div', {
      id: 'ms-auth-overlay',
      role: 'presentation',
      style: {
        position: 'fixed',
        inset: '0',
        background: 'rgba(0,0,0,0.55)',
        display: 'flex',
        alignItems: 'center',
        justifyContent: 'center',
        zIndex: '9999'
      }
    });

    // panel
    const panel = createEl('div', {
      id: 'ms-auth-panel',
      role: 'dialog',
      'aria-modal': 'true',
      'aria-labelledby': 'ms-auth-title',
      style: {
        width: '420px',
        maxWidth: '95%',
        background: '#fff',
        borderRadius: '10px',
        padding: '20px',
        boxSizing: 'border-box',
        boxShadow: '0 12px 30px rgba(0,0,0,0.35)',
        position: 'relative',
        fontFamily: 'system-ui, -apple-system, "Segoe UI", Roboto, "Helvetica Neue", Arial',
        color: '#222'
      }
    });

    // close button (shifted upward to avoid overlap)
    const closeBtn = createEl('button', {
      class: 'ms-close',
      html: '&times;',
      'aria-label': 'Close',
      style: {
        position: 'absolute',
        right: '-8px',
        top: '-12px',         // shifted up to avoid overlapping form fields
        border: 'none',
        background: '#fff',
        width: '36px',
        height: '36px',
        borderRadius: '50%',
        boxShadow: '0 2px 6px rgba(0,0,0,0.15)',
        fontSize: '20px',
        cursor: 'pointer',
        lineHeight: '1',
        zIndex: '10000'
      }
    });
    closeBtn.addEventListener('click', () => overlay.remove());

    // header / tabs
    const header = createEl('div', {
      style: { display: 'flex', alignItems: 'center', justifyContent: 'space-between', marginBottom: '12px' }
    });
    const title = createEl('div', { id: 'ms-auth-title', html: '<strong>Welcome</strong><div style="font-size:12px;color:#666">Sign in or create an account</div>' });
    const tabs = createEl('div', { style: { display: 'flex', gap: '8px' } });
    const tLogin = createEl('button', {
      id: 'ms-tab-login',
      class: 'ms-tab ms-active',
      html: 'Login',
      style: {
        padding: '6px 10px',
        borderRadius: '6px',
        border: '1px solid #ddd',
        background: '#62259b',
        color: '#fff',
        cursor: 'pointer'
      }
    });
    const tSignup = createEl('button', {
      id: 'ms-tab-signup',
      class: 'ms-tab',
      html: 'Sign up',
      style: {
        padding: '6px 10px',
        borderRadius: '6px',
        border: '1px solid #ddd',
        background: '#f4f4f4',
        cursor: 'pointer'
      }
    });
    tLogin.addEventListener('click', () => switchTab(panel, 'login'));
    tSignup.addEventListener('click', () => switchTab(panel, 'signup'));
    tabs.appendChild(tLogin);
    tabs.appendChild(tSignup);
    header.appendChild(title);
    header.appendChild(tabs);

    const social = createEl('div', { style: { display: 'none' } });

    // divider
    const orRow = createEl('div', {
      style: { textAlign: 'center', color: '#888', fontSize: '13px', margin: '8px 0' },
      html: '<span style="background:#fff;padding:0 8px">or</span>'
    });

    // login form
    const loginForm = createEl('form', {
      id: 'ms-login-form',
      style: { display: 'block' }
    });
    loginForm.innerHTML = `
       <label style="display:block;margin:8px 0;font-size:13px">Email
         <input name="email" type="email" required style="width:100%;padding:9px 10px;margin-top:6px;border:1px solid #ccc;border-radius:6px">
       </label>
       <label style="display:block;margin:8px 0;font-size:13px">Password
         <input name="password" type="password" required style="width:100%;padding:9px 10px;margin-top:6px;border:1px solid #ccc;border-radius:6px">
       </label>
       <div style="display:flex;justify-content:space-between;align-items:center;margin-top:8px">
        <label style="font-size:13px;color:#555"><input type="checkbox" name="remember" style="margin-right:6px">Remember me</label>
        <button type="button" id="ms-forgot-btn" style="font-size:13px;color:#62259b;background:none;border:none;padding:0;cursor:pointer">Forgot?</button>
       </div>
       <div style="margin-top:12px;display:flex;justify-content:flex-end">
         <button type="submit" style="padding:10px 14px;border-radius:6px;border:none;background:#62259b;color:#fff;cursor:pointer">Login</button>
       </div>
       <div id="ms-login-msg" style="color:#b00020;margin-top:8px;min-height:18px;font-size:13px"></div>
     `;

    // signup form
    const signupForm = createEl('form', {
      id: 'ms-signup-form',
      style: { display: 'none' }
    });
    signupForm.innerHTML = `
      <label style="display:block;margin:8px 0;font-size:13px">Name
        <input name="name" type="text" required style="width:100%;padding:9px 10px;margin-top:6px;border:1px solid #ccc;border-radius:6px">
      </label>
      <label style="display:block;margin:8px 0;font-size:13px">Email
        <input name="email" type="email" required style="width:100%;padding:9px 10px;margin-top:6px;border:1px solid #ccc;border-radius:6px">
      </label>
      <label style="display:block;margin:8px 0;font-size:13px">Password
        <input name="password" type="password" required minlength="6" style="width:100%;padding:9px 10px;margin-top:6px;border:1px solid #ccc;border-radius:6px">
      </label>
      <label style="display:block;margin:8px 0;font-size:13px">Confirm Password
        <input name="confirm" type="password" required minlength="6" style="width:100%;padding:9px 10px;margin-top:6px;border:1px solid #ccc;border-radius:6px">
      </label>
      <div style="margin-top:12px;display:flex;justify-content:flex-end">
        <button type="submit" style="padding:10px 14px;border-radius:6px;border:none;background:#62259b;color:#fff;cursor:pointer">Create account</button>
      </div>
      <div id="ms-signup-msg" style="color:#b00020;margin-top:8px;min-height:18px;font-size:13px"></div>
    `;

    // reset password form (hidden by default)
    const resetForm = createEl('form', {
      id: 'ms-reset-form',
      style: { display: 'none' }
    });
    resetForm.innerHTML = `
      <h4 style="margin:0 0 8px 0">Reset password</h4>
      <label style="display:block;margin:8px 0;font-size:13px">Email
        <input name="email" type="email" required style="width:100%;padding:9px 10px;margin-top:6px;border:1px solid #ccc;border-radius:6px">
      </label>
      <div style="display:flex;justify-content:space-between;align-items:center;margin-top:8px">
        <button type="button" id="ms-reset-back" style="padding:8px 12px;border-radius:6px;border:1px solid #ddd;background:#f4f4f4;cursor:pointer">Back</button>
        <button type="submit" style="padding:10px 14px;border-radius:6px;border:none;background:#62259b;color:#fff;cursor:pointer">Send reset link</button>
      </div>
      <div id="ms-reset-msg" style="color:#1b7f3a;margin-top:8px;min-height:18px;font-size:13px"></div>
    `;

    // forgot/reset handlers (operate on forms even before added to DOM)
    const forgotBtn = loginForm.querySelector('#ms-forgot-btn');
    if (forgotBtn)
	{
      forgotBtn.addEventListener('click', () => {
        loginForm.style.display = 'none';
        signupForm.style.display = 'none';
        resetForm.style.display = 'block';
        const e = resetForm.querySelector('input[name="email"]');
        if (e)
			setTimeout(() => e.focus(), 50);
      });
    }

    // back button to return to login
    resetForm.addEventListener('click', (ev) => {
      	if (ev.target && ev.target.id === 'ms-reset-back')
		{
			resetForm.style.display = 'none';
			loginForm.style.display = 'block';
      	}
    });

    // reset form submit handler
    resetForm.addEventListener('submit', async (e) => {
		e.preventDefault();
		const email = resetForm.email.value.trim();
		const msg = resetForm.querySelector('#ms-reset-msg');
		msg.textContent = '';
		if (!validateEmail(email))
		{
			msg.style.color = '#b00020';
			msg.textContent = 'Enter a valid email.'; 
			return; 
		}
      	try
		{
			const res = await postJSON('/api/auth/forgot', { email });
			if (!res.ok) {
				msg.style.color = '#b00020';
				msg.textContent = res.data?.message || `Request failed (${res.status})`;
				return;
			}
			msg.style.color = '#1b7f3a';
			msg.textContent = res.data?.message || 'If an account exists you will receive reset instructions.';
      	}
		catch (err)
		{
			msg.style.color = '#b00020';
			msg.textContent = 'Network error';
			console.error(err);
      	}
    });

    // add inline password strength / match helper after innerHTML is set
    const pwdInput = signupForm.querySelector('input[name="password"]');
    const pwdConfirm = signupForm.querySelector('input[name="confirm"]');
    const signupMsg = panel ? panel.querySelector('#ms-signup-msg') : null;
    if (pwdInput)
	{
      	const strengthEl = createEl('div', {
			id: 'ms-pass-strength',
			style: {
				fontSize: '12px',
				color: '#444',
				marginTop: '6px',
				minHeight: '18px'
        	}
      	});
		// insert after password input
		pwdInput.parentNode.insertBefore(strengthEl, pwdInput.nextSibling);
		pwdInput.addEventListener('input', () => {
			const s = passwordStrengthText(pwdInput.value);
			let color = '#b00020';
			if (s === 'Very strong' || s === 'Strong')
				color = '#1b7f3a';
			else if (s === 'Medium')
				color = '#b77f00';
			strengthEl.textContent = s ? `Password: ${s}` : '';
			strengthEl.style.color = color;
		});
    }
    if (pwdConfirm && pwdInput)
	{
		const matchEl = createEl('div', {
			id: 'ms-pass-match',
			style: { fontSize: '12px', color: '#444', marginTop: '6px', minHeight: '18px' }
		});
		pwdConfirm.parentNode.insertBefore(matchEl, pwdConfirm.nextSibling);
		const updateMatch = () => {
			if (!pwdConfirm.value)
			{
				matchEl.textContent = '';
				return;
			}
			matchEl.textContent = (pwdInput.value === pwdConfirm.value) ? 'Passwords match' : 'Passwords do not match';
			matchEl.style.color = (pwdInput.value === pwdConfirm.value) ? '#1b7f3a' : '#b00020';
		};
		pwdInput.addEventListener('input', updateMatch);
		pwdConfirm.addEventListener('input', updateMatch);
    }

    // submit handlers
    loginForm.addEventListener('submit', async (e) => {
		e.preventDefault();
		const email = loginForm.email.value.trim();
		const password = loginForm.password.value;
		const msg = panel.querySelector('#ms-login-msg');
		msg.textContent = '';
		if (!email || !password)
		{
			msg.textContent = 'Email and password required.'; 
			return;
		}
		if (!validateEmail(email))
		{
			msg.textContent = 'Enter a valid email address.';
			return;
		}
		if (password.length < 6)
		{
			msg.textContent = 'Password must be at least 6 characters.';
			return;
		}
		try
		{
			const res = await postJSON('/api/auth/login', { email, password });
			if (!res.ok)
			{
				msg.textContent = res.data?.message || `Login failed (${res.status})`;
				return;
			}
			if (res.data?.token)
				localStorage.setItem('token', res.data.token);
			overlay.remove();
			// redirect to dashboard after login
			window.location.href = '/dashboard.html';
		}
		catch (err)
		{
			msg.textContent = 'Network error';
			console.error(err);
		}
    });

    signupForm.addEventListener('submit', async (e) => {
		e.preventDefault();
		const name = signupForm.name.value.trim();
		const email = signupForm.email.value.trim();
		const password = signupForm.password.value;
		const confirm = signupForm.confirm.value;
		const msg = panel.querySelector('#ms-signup-msg');
		msg.textContent = '';
		if (!name || !email || !password)
		{
			msg.textContent = 'All fields required.';
			return;
		}
		if (!validateEmail(email))
		{
			msg.textContent = 'Enter a valid email address.';
			return; 
		}
		if (password !== confirm)
		{
			msg.textContent = 'Passwords do not match.';
			return;
		}
		if (!validateStrongPassword(password))
		{
			msg.textContent = 'Password must be at least 8 characters and include uppercase, lowercase, a number, and a special character.';
			return;
		}
		try
		{
			const username = name.replace(/\s+/g, '').toLowerCase() || (email.split('@')[0] || '');
			const payload = { name, username, email, password };
			const res = await tryPostWithFallback(
				['/api/auth/register', '/api/auth/signup', '/auth/register', '/auth/signup'],
				payload
			);
			if (!res.ok)
			{
				const info = typeof res.data === 'string' ? res.data : (res.data && res.data.message) ? res.data.message : JSON.stringify(res.data || {});
				msg.textContent = `Signup failed (${res.status}) ${res.url ? ' at ' + res.url : ''}: ${info}`;
				return;
			}
			// do not auto-login after signup — show signup-success page and wait for user to go home and login
			overlay.remove();
			window.location.href = '/signup-success.html';
		}
		catch (err)
		{
			msg.textContent = 'Network error';
			console.error(err);
		}
    });

    // assemble panel
    panel.appendChild(closeBtn);
    panel.appendChild(header);
    panel.appendChild(social);
    panel.appendChild(orRow);
    panel.appendChild(loginForm);
    panel.appendChild(signupForm);
    panel.appendChild(resetForm);
    overlay.appendChild(panel);
    document.body.appendChild(overlay);

    // click outside to close
    overlay.addEventListener('click', (ev) => {
      if (ev.target === overlay)
		overlay.remove();
    });

    // esc to close
    function escHandler(e) {
		if (e.key === 'Escape')
		{
			overlay.remove();
			document.removeEventListener('keydown', escHandler);
		}
    }
    document.addEventListener('keydown', escHandler);

    // default focus
    switchTab(panel, 'login');
  };

  // add logout helper near the end of the file (exported globally)
  window.logout = function ()
  {
    try
	{
		localStorage.removeItem('token');
	}
	catch (e) {}
    window.location.href = '/';
  };
})();

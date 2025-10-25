const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
const User = require('../models/User');

//Generate JWT token helper
const generateToken = (user) => {
  return jwt.sign(
    { 
      id: user._id,
      email: user.email,
      role: user.role
    },
    process.env.JWT_SECRET,
    { 
      expiresIn: '7d' 
    }
  );
};

// @desc    Register a new user
// @route   POST /api/auth/register
exports.registerUser = async (req, res) => {
  try 
  {
    const { name, email, password } = req.body;

    //Checking all fields
    if (!name || !email || !password) 
      return res.status(400).json({ message: 'All fields are required' });

    //Checking if user already exists
    const existingUser = await User.findOne({ email });
    if (existingUser) 
      return res.status(400).json({ message: 'User already exists' });

    //Hash password before saving
    const salt = await bcrypt.genSalt(10);
    const hashedPassword = await bcrypt.hash(password, salt);

    //Create new user
    const user = await User.create({
      name,
      email,
      password: hashedPassword,
    });

    //Generate token
    const token = generateToken(user);

    res.status(201).json({
      message: 'User registered successfully',
      token,
      user: 
      {
        id: user._id,
        name: user.name,
        email: user.email,
      },
    });
  }
  catch (error)
  {
    console.error('Register Error:', error);
    res.status(500).json({ message: 'Server error' });
  }
};

// @desc    Login user
// @route   POST /api/auth/login
exports.loginUser = async (req, res) => {
  try
  {
    const { email, password } = req.body;

    //Validate input
    if (!email || !password)
      return res.status(400).json({ message: 'Please provide email and password' });

    //Find user
    const user = await User.findOne({ email });
    if (!user)
      return res.status(401).json({ message: 'Invalid credentials' });

    //Compare passwords
    const isMatch = await bcrypt.compare(password, user.password);
    if (!isMatch)
      return res.status(401).json({ message: 'Invalid credentials' });

    //Generate token
    const token = generateToken(user);

    res.status(200).json({
      message: 'Login successful',
      token,
      user: 
      {
        id: user._id,
        name: user.name,
        email: user.email,
      },
    });
  }
  catch (error)
  {
    console.error('Login Error:', error);
    res.status(500).json({ message: 'Server error' });
  }
};

// @desc    Get current logged-in user (Protected route)
// @route   GET /api/auth/me
exports.me = async (req, res) => {
  try
  {
    if (!req.user)
      return res.status(404).json({ message: 'User not found' });
    //req.user already excludes password if middleware used select('-password')
    return res.json(req.user); 
  }
  catch (err)
  {
    console.error('authController.me error:', err);
    return res.status(500).json({ message: 'Server error' });
  }
};


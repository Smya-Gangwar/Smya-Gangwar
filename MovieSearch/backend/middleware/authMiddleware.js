const jwt = require('jsonwebtoken');
const User = require('../models/User');

module.exports = async function authMiddleware(req, res, next) 
{
  try 
  {
    const auth = req.headers.authorization || '';

    if (!auth.startsWith('Bearer '))
      return res.status(401).json({ message: 'No token provided' });

    let token = auth.split(' ')[1] || '';
    token = token.replace(/(^["'\s]+|["'\s]+$)/g, '').trim(); // clean token

    if (!token)
      return res.status(401).json({ message: 'No token provided' });

    const decoded = jwt.verify(token, process.env.JWT_SECRET);
    const user = await User.findById(decoded.id).select('-password');

    if (!user)
      return res.status(401).json({ message: 'Invalid token: user not found' });

    req.user = user;
    next();
  } 
  catch (err)
  {
    console.error('Auth middleware error:', err.message || err);
    return res.status(401).json({ message: err.message || 'Authentication failed' });
  }
};


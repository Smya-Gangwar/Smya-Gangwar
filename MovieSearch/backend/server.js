const express = require('express');
const mongoose = require('mongoose');
const dotenv = require('dotenv');
const cors = require('cors');
const path = require('path');

dotenv.config();

const app = express();

// Middleware
app.use(express.json());
app.use(cors());

// Connect to MongoDB
mongoose.connect(process.env.MONGO_URI)
  .then(() => console.log('MongoDB Connected'))
  .catch((err) => {
    console.error('MongoDB connection error:', err);
    process.exit(1);
  });

// Import routes
const authRoutes = require('./routes/authRoutes');

// Use API routes first
app.use('/api/auth', authRoutes);

// quick debug: request logger and ping endpoint
app.use((req, res, next) => {
  console.log(new Date().toISOString(), req.method, req.url);
  next();
});

app.get('/ping', (req, res) => res.send('pong'));

// Serve frontend static files AFTER API routes
app.use(express.static(path.join(__dirname, 'public')));

// Serve favicon files at root (site.webmanifest, apple-touch-icon, favicon-*.png, etc.)
app.use(express.static(path.join(__dirname, 'favicon')));

// Serve poster images under /poster
app.use('/poster', express.static(path.join(__dirname, 'poster')));

// Catch-all route to serve index.html for frontend routing
app.get('*', (req, res) => {
  res.sendFile(path.join(__dirname, 'public', 'index.html'));
});

// Global error handler (optional)
app.use((err, req, res, next) => {
  console.error('Server Error:', err);
  res.status(500).json({
    message: 'Server error',
    error: err.message 
  });
});

// Start server (replace current start/listen block)
const DEFAULT_PORT = process.env.PORT ? parseInt(process.env.PORT, 10) : 5000;

function tryListen(port) {
  const server = app.listen(port, () => {
    console.log(`Server running on http://localhost:${server.address().port}`);
  });

  server.on('error', (err) => {
    if (err.code === 'EADDRINUSE')
    {
      console.log(`Port ${port} in use, trying ${port + 1}`);
      tryListen(port + 1);
    }
    else
      {
      console.error('Server error:', err);
      process.exit(1);
    }
  });
}

tryListen(DEFAULT_PORT);
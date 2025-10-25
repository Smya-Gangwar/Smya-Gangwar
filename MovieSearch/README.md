# 🎬 MovieSearch

**MovieSearch** is a Web-based project for a movie agregation platform. The concept aims to provide users with a unified interface to explore which movies are available on which streaming platforms (like Netflix, Prime Video, etc.).

This project focused purely on the frontend using **HTML**, **CSS**, and a touch of **JavaScript** for UI interactivity intially. It has been enhanced with a little bit of backend setup allowing users to login/signup on the website using JS and MongoDB database.

---

## 📌 Features

- ✨ Clean, responsive layout for homepage
- 🎞️ Sections to display featured movies and platforms
- 🔍 Placeholder search functionality for finding movies
- 🔐 Login/Signup buttons (functional)
- 🎨 Basic use of animations, hover effects, and custom styling

---

## 🛠️ Tech Stack

- **HTML5** - structure and markup
- **CSS3** - styling and layout
- **JavaScript** - for toggling login/signup UI (fully functional)
- **MongoDB** - Storing credentials

---

## 🚀 How to Run Locally

Follow these steps on macOS (works similarly on Linux). 
(Assumed with no dependencies pre-installed)

1) Install Homebrew (if don't have)
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

2) Install system tools (git, node, npm)
```bash
brew install git
brew install node      # installs node + npm
```

3) Install MongoDB (choose one)
- Local (Homebrew):
```bash
brew tap mongodb/brew
brew install mongodb-community@6.0
brew services start mongodb-community@6.0
# verify
mongosh --eval "db.adminCommand({ping:1})"
```
- Or use MongoDB Atlas (on Cloud). Create a free cluster and copy the connection string.

4) Clone the repository
```bash
git clone https://github.com/Smya-Gangwar/MovieSearch.git
cd MovieSearch
```
(If you already have the folder locally, cd into it.)

5) Install Node dependencies
- If package.json is at project root:
```bash
npm install
```
- If there is a separate backend folder with its own package.json, also run:
```bash
cd backend
npm install
cd ..
```

6) Create .env file for backend (Sample)
- In backend folder create a file named `.env` with at least:
```
MONGO_URI=mongodb://localhost:27017/moviesearch
JWT_SECRET=<your_jwt_secret_here>
PORT=5000
SALT_ROUNDS=10
```
- If using MongoDB Atlas, set MONGO_URI to the Atlas connection string.

7) Start the server
- From project root or backend folder (depending on scripts):
```bash
# from backend if server.js is there
cd backend
npm run dev    # uses nodemon if configured
# or
node server.js
```

8) Open the app
- Visit http://localhost:5000 in your browser (port comes from your .env or server logs).

9) Quick API tests (optional)
- Register:
```bash
curl -i -X POST http://localhost:5000/api/auth/register \
  -H "Content-Type: application/json" \
  -d '{"name":"Test User","username":"testuser","email":"test@example.com","password":"Secret123!"}'
```
- Login:
```bash
curl -i -X POST http://localhost:5000/api/auth/login \
  -H "Content-Type: application/json" \
  -d '{"email":"test@example.com","password":"Secret123!"}'
```
- Get profile (replace <TOKEN> with returned JWT):
```bash
curl -i -H "Authorization: Bearer <TOKEN>" http://localhost:5000/api/auth/me
```
const express = require('express');
const app = express();

// ... other middleware and routes

// Error handling middleware
app.use((err, req, res, next) => {
  console.error(err.stack); // Log the error to the console

  // Set appropriate status code based on error type
  let status = 500; // Default status code for internal server errors

  if (err.name === 'ValidationError') {
    status = 400; // Bad Request
  } else if (err.name === 'UnauthorizedError') {
    status = 401; // Unauthorized
  } else if (err.name === 'ForbiddenError') {
    status = 403; // Forbidden
  } else if (err.name === 'NotFound') {
    status = 404; // Not Found
  }

  res.status(status).json({
    error: {
      message: err.message,
      status: status,
    },
  });
});

module.exports = app;
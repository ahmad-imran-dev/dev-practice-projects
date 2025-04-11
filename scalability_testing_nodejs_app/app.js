var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
// Added dotenv setup
require('dotenv').config();

var indexRouter = require('./routes/index');
var app = express();
var dbConnection = require("./utils/db_connection");

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));
dbConnection();

app.use('/api', indexRouter);

module.exports = app;

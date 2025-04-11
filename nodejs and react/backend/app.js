var express = require("express");
var path = require("path");
var cookieParser = require("cookie-parser");
var cors = require("cors");
var logger = require("morgan");
var config = require("config");
var databaseConnection = require("./utils/databaseConnection");
require("dotenv").config();
var origin = `${config.get("client-url")}`;

var app = express();

app.use(logger("dev"));
app.use(express.json());
app.use(cors({ origin, credentials: true }));
app.use(express.urlencoded({ extended: true }));
// app.use(express.json());
app.use(cookieParser());
app.use(express.static(path.join(__dirname, "public")));

// databaseConnection();


module.exports = app;

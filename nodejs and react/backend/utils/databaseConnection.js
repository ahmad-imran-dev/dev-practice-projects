const mongoose = require("mongoose");
const debug = require("../debuggers/customDebugger");

const databaseConnection = async () => {
  const connectionUri = process.env.MONGODB_CONNECTION_URI;

  await mongoose
    .connect(connectionUri)
    .then(function () {
      debug("Connected to Database");
    })
    .catch((err) => {
      debug(err);
    });
};

module.exports = databaseConnection;

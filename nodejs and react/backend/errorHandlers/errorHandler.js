// Error handler middleware
const debug = require("../debuggers/customDebugger");

function errorHandler(err, req, res, next) {
  let errStatus = err.status || 500;
  let errMsg = err.message || "Internal server error";
  const error = { message: errMsg, status: errStatus };

  debug(err);
  return res.status(errStatus).json({ error });
}

module.exports = errorHandler;

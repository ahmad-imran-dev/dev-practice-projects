const mongoose = require("mongoose");

const databaseConnection = async () => {
    const DATABASE_URI = process.env.DATABASE_URI;

    await mongoose
        .connect(DATABASE_URI)
        .then(function () {
            console.log("Connected to Database");
        })
        .catch((err) => {
            console.log(err);
        });
};

module.exports = databaseConnection;

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question("Input Something: ", (input) => {
    input = input;
    console.log(input);
    rl.close();
});


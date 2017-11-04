const path = require('path');

module.exports = {
  entry: {
    basic: './lib/js/examples/basic/basic.js',
  },
  output: {
    path: path.join(__dirname, "bundledOutputs"),
    filename: '[name].js',
  },
};

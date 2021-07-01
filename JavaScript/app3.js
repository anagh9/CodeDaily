function x() {
  var a = 7;
  function y() {
    console.log(a);
  }
  y();
}

x();

// Clousure => Clousure is a combination of function and lexical scope budled together forms a clousure

// A closure is the combination of a function bundled together (enclosed) with references to its surrounding state (the lexical environment). In other words, a closure gives you access to an outer function’s scope from an inner function. In JavaScript, closures are created every time a function is created, at function creation time.

function z() {
  for (let i = 0; i <= 5; i++) {
    setTimeout(() => {
      console.log(i);
    }, i * 3000);
  }

  console.log("Hello JS");
}

z();

function zz() {
  for (var i = 0; i <= 5; i++) {
    function close(x) {
      setTimeout(() => {
        console.log(x);
      }, x * 3000);
    }
    close(i);
  }

  console.log("Hello JS");
}

zz();

// Function Statememnt

function a() {
  console.log("a called");
}

// Function Expression

var b = function () {
  console.log("B called");
};

// Anonymous Function

const x = function () {};
// Parameter and argument
var t = function (param1, param2) {};

t(arg1, arg2);

// The value which is passed are known as argument and the value which gets those values are called parameter

// First Class Function
// Passing another function in another function
// when function treated as value passed as args to another function and get by another function as params this ability are known as first class function.

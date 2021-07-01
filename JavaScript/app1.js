var n = 2;
function square(num) {
  var ans = num * num;
  return ans;
}

var square2 = square(n);
var square4 = square(4);

// Memory Execution of all variable first
// Global Execution Context Created
// Call Stack 

// Hoisting in Javascript => In JavaScript, a variable can be declared after it has been used. In other words; a variable can be used before it has been declared. 

getName();
console.log(x);

var x =32;

function getName(){
    console.log("Get Name called");
}


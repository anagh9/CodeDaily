// How Function Work

var x = 1;
a();
b();
console.log(x);

function a() {
  var x = 10;
  console.log(x);
}

function b() {
  var x = 100;
  console.log(x);
}

// output => 10 , 100 , 1

// Memory allocation first
// Then Execution Context is Created
// Then Pushed In Call Stack

/*** Scope and lexical enviroment */
// let and Const are hoisted is in temporaral dead zone

/**Block => all Variable and function inside the block */
if (x) {
  // Compound Statement Grouped Together
  var a = 10;
  console.log(a);
}

{
  var a = 13;
  var b = 43;
  function c() {
    console.log("C function Called");
  }
}

// Shawdowing => Same Name Variable Outside the Block

var a = 100;
{
  var a = 10;
  var b = 20;
  const c = 56;
  console.log(a);
  console.log(b);
  console.log(c);
}

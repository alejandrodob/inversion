open Dom;
open Draw;

let canvas = getElementById("screen");

let screen = getContext2d(canvas);

circle({x: 100., y: 100.}, 40., screen);
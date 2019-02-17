open Dom;

type canvasContext2d;

[@bs.get] external elementWidth: element => int = "width";

[@bs.get] external elementHeight: element => int = "height";

[@bs.val]
external getElementById: string => element = "document.getElementById";

[@bs.val] external document: element = "document";

[@bs.send]
external getContext2d: (element, [@bs.as "2d"] _) => canvasContext2d =
  "getContext";

[@bs.send]
external fillRect: (canvasContext2d, int, int, int, int) => unit = "fillRect";

[@bs.send]
external clearRect: (canvasContext2d, int, int, int, int) => unit =
  "clearRect";

[@bs.send] external beginPath: canvasContext2d => unit = "beginPath";

[@bs.send] external closePath: canvasContext2d => unit = "closePath";

[@bs.send]
external arc:
  (canvasContext2d, float, float, float, float, float, bool) => unit =
  "arc";

[@bs.send] external moveTo: (canvasContext2d, float, float) => unit = "moveTo";

[@bs.send] external lineTo: (canvasContext2d, float, float) => unit = "lineTo";

[@bs.send] external fill: canvasContext2d => unit = "fill";

[@bs.send] external stroke: canvasContext2d => unit = "stroke";

[@bs.set]
external setFillStyle: (canvasContext2d, string) => unit = "fillStyle";

[@bs.set]
external setStrokeStyle: (canvasContext2d, string) => unit = "strokeStyle";

[@bs.val]
external requestAnimationFrame: (int => int) => int = "requestAnimationFrame";

[@bs.val] external cancelAnimationFrame: int => unit = "cancelAnimationFrame";

[@bs.send]
external addEventListener: (element, string, event => unit) => unit =
  "addEventListener";

[@bs.get] external getKeyCode: event => int = "keyCode";

[@bs.send]
external getBoundingClientRect: element => domRect = "getBoundingClientRect";

[@bs.get] external domRectLeft: domRect => float = "left";

[@bs.get] external domRectTop: domRect => float = "top";

[@bs.get] external clientX: event => float = "clientX";

[@bs.get] external clientY: event => float = "clientY";

let getCursorCoords = (elem, evt) => {
  let rect = getBoundingClientRect(elem);
  (clientX(evt) -. domRectLeft(rect), clientY(evt) -. domRectTop(rect));
};
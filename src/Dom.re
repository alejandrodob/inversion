type element;

type context;

type event;

type window;

[@bs.get] external elementWidth: element => int = "width";

[@bs.get] external elementHeight: element => int = "height";

[@bs.val]
external getElementById: string => element = "document.getElementById";

[@bs.val] external document: element = "document";

[@bs.send]
external getContext2d: (element, [@bs.as "2d"] _) => context = "getContext";

[@bs.send]
external fillRect: (context, int, int, int, int) => unit = "fillRect";

[@bs.send]
external clearRect: (context, int, int, int, int) => unit = "clearRect";

[@bs.send] external beginPath: context => unit = "beginPath";

[@bs.send] external closePath: context => unit = "closePath";

[@bs.send]
external arc: (context, float, float, float, float, float, bool) => unit =
  "arc";

[@bs.send] external moveTo: (context, float, float) => unit = "moveTo";

[@bs.send] external lineTo: (context, float, float) => unit = "lineTo";

[@bs.send] external fill: context => unit = "fill";

[@bs.send] external stroke: context => unit = "stroke";

[@bs.val]
external requestAnimationFrame: (int => int) => int = "requestAnimationFrame";

[@bs.val] external cancelAnimationFrame: int => unit = "cancelAnimationFrame";

[@bs.send]
external addEventListener: (element, string, event => unit) => unit =
  "addEventListener";

[@bs.get] external getKeyCode: event => int = "keyCode";
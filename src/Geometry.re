let pi = acos(-1.);

type point = (float, float);

type circumference = {
  centre: point,
  radius: float,
};

type line = (point, point);

let distance = ((x1, x2): point, (y1, y2): point) =>
  sqrt((x1 -. y1) ** 2. +. (x2 -. y2) ** 2.);

let normalize = ((v1, v2)) => {
  switch (distance((v1, v2), (0., 0.))) {
  | 0. => (v1, v2)
  | d => (v1 /. d, v2 /. d)
  };
};

let inverseOfPoint = ({centre, radius}, (p1, p2)): point => {
  let (c1, c2) = centre;
  let inverseDistance = radius ** 2. /. distance((c1, c2), (p1, p2));
  let (v1, v2) = normalize((p1 -. c1, p2 -. c2));
  (v1 *. inverseDistance +. c1, v2 *. inverseDistance +. c2);
};
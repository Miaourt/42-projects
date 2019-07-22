let dimx : int = 1600
let dimy : int = 900

let draw_gameover () : unit =
  Graphics.clear_graph ();
  Graphics.moveto (dimx / 2 - 150) (dimy / 2);
  Graphics.set_font "-*-fixed-medium-r-semicondensed--50-*-*-*-*-*-iso8859-1";
  Graphics.draw_string "GAME OVER";
  Graphics.moveto (dimx / 2 - 150) (dimy / 2 - 200);
  Graphics.draw_string "Continue ? [y/N]";
  Graphics.set_font "fixed"

let draw_gauge (name : string) (value : int) (x : int) (y : int) : unit =
  let w = 150 in
  let h = 30 in
  Graphics.moveto (x + w / 4 + 20) y;
  Graphics.draw_string name;
  Graphics.set_color Graphics.white;
  Graphics.fill_rect x (y - 40) w h;
  Graphics.set_color Graphics.black;
  Graphics.draw_rect x (y - 40) w h;
  ( if value <= 10
  then
    Graphics.set_color Graphics.red
  else if value <= 30
  then
    Graphics.set_color (Graphics.rgb 0xFF 0x45 0)
  else if value <= 50
  then
    Graphics.set_color Graphics.yellow
  else
    Graphics.set_color Graphics.green );
  Graphics.fill_rect x (y - 40) (w * value / 100) h;
    Graphics.set_color Graphics.black

let draw_action (name : string) (x : int) (y : int) (sel : string) =
  let w, h = 100, 70 in
  if name <> sel
  then (
    Graphics.set_color Graphics.white;
    Graphics.fill_rect x y w h;
    Graphics.set_color Graphics.black;
    Graphics.draw_rect x y w h;
    Graphics.moveto (x + 40) (y + 30);
    Graphics.draw_string name )
  else (
    Graphics.fill_rect x y w h;
    Graphics.moveto (x + 40) (y + 30);
    Graphics.set_color Graphics.white;
    Graphics.draw_string name;
    Graphics.set_color Graphics.black; )

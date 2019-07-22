class creature hp hy e happy i =
object (self)
  val img : Graphics.image = i
  val mutable selected : string = "EAT"
  val mutable health : int = hp
  val mutable hygiene : int = hy
  val mutable energy : int = e
  val mutable happiness : int = happy

  method private add a b =
    if a + b > 100
    then
      100
    else if a + b < 0
    then
      0
    else
      a + b

  method sleep : unit =
    health <- (self#add health (-20));
    energy <- (self#add energy 10);
    happiness <- (self#add happiness 5)

  method eat : unit =
    health <- (self#add health 25);
    energy <- (self#add energy (-10));
    hygiene <- (self#add hygiene (-20));
    happiness <- (self#add happiness 5)

  method thunder : unit =
    health <- (self#add health (-20));
    energy <- (self#add energy 25);
    happiness <- (self#add happiness (-20))

  method bath : unit =
    health <- (self#add health (-20));
    energy <- (self#add energy (-10));
    hygiene <- (self#add hygiene 25);
    happiness <- (self#add happiness 5)

  method kill : unit =
    health <- (self#add health (-20));
    energy <- (self#add energy (-10));
    happiness <- (self#add happiness 20)

  method save : unit =
    Serializer.save health hygiene energy happy

  method get_img : Graphics.image = img

  method do_action : unit =
    if selected = "EAT"
    then
      self#eat
    else if selected = "THUNDER"
    then
      self#thunder
    else if selected = "BATH"
    then
      self#bath
    else if selected = "KILL"
    then
      self#kill
    else if selected = "SLEEP"
    then
      self#sleep

  method change_selection direction : unit =
    if selected = "EAT" && direction = 1
    then
      selected <- "THUNDER"
    else if selected = "THUNDER" && direction = 0
    then
      selected <- "EAT"
    else if selected = "THUNDER" && direction = 1
    then
      selected <- "BATH"
    else if selected = "BATH" && direction = 0
    then
      selected <- "THUNDER"
    else if selected = "BATH" && direction = 1
    then
      selected <- "KILL"
    else if selected = "KILL" && direction = 0
    then
      selected <- "BATH"
    else if selected = "KILL" && direction = 1
    then
      selected <- "SLEEP"
    else if selected = "SLEEP" && direction = 0
    then
      selected <- "KILL"

  method deplete : unit =
    health <- (self#add health (-1))

  method is_dead : bool =
    (health = 0) || (energy = 0) || (hygiene = 0) || (happiness = 0)

  method draw : unit =
    (*    Graphics.clear_graph ();*)
    let gauge_offset = 50 in
    let gauge_y = Gui.dimy - 70 in
    Gui.draw_gauge "HEALTH" health (Gui.dimx / 4 + gauge_offset) gauge_y;
    Gui.draw_gauge "HYGIENE" hygiene (Gui.dimx / 4 + gauge_offset + 200) gauge_y;
    Gui.draw_gauge "ENERGY" energy (Gui.dimx / 4 + gauge_offset + 400) gauge_y;
    Gui.draw_gauge "HAPPY" happiness (Gui.dimx / 4 + gauge_offset + 600) gauge_y;
    Graphics.draw_image img 500 300;
    let action_xoffset = 100 in
    let action_yoffset = 50 in
    Gui.draw_action "EAT" (Gui.dimx / 5) action_yoffset selected;
    Gui.draw_action "THUNDER" (Gui.dimx / 5 + action_xoffset + 100) action_yoffset selected;
    Gui.draw_action "BATH" (Gui.dimx / 5 + action_xoffset + 300) action_yoffset selected;
    Gui.draw_action "KILL" (Gui.dimx / 5 + action_xoffset + 500) action_yoffset selected;
    Gui.draw_action "SLEEP" (Gui.dimx / 5 + action_xoffset + 700) action_yoffset selected;

end

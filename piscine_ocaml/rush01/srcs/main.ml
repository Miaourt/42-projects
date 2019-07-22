let rec draw_loop crea sec =
  crea#draw;
  ( if Graphics.key_pressed ()
  then
    match Graphics.read_key () with
      '[' -> crea#change_selection 0
    | ']' -> crea#change_selection 1
    | '\013' -> crea#do_action
    | 'q' | '\033' -> raise Exit;
    | _ -> ());
  if crea#is_dead
  then (
    crea#save;
    Gui.draw_gameover ();
    match Graphics.read_key () with
      'y' | 'Y' | 'o' | 'O' -> (Graphics.clear_graph ();
                                draw_loop (new Tama.creature 100 100 100 100 crea#get_img) (Unix.time ()) )
      | _ -> ()
  )
  else if Unix.time () >= (sec +. 1.)
  then (
    crea#save;
    crea#deplete;
    draw_loop crea (Unix.time ()) )
  else
    draw_loop crea sec

let () =
  Graphics.open_graph @@ " " ^ (string_of_int Gui.dimx) ^ "x" ^ (string_of_int Gui.dimy);
  Graphics.set_window_title "GUDETAMA";
  Graphics.auto_synchronize true;
  let loaded = Images.lire_image "ressources/gudetama.png" in
  let img = Graphics.make_image loaded in
  let health, energy, hygiene, happy = Serializer.load () in
  let crea = new Tama.creature health energy hygiene happy img in
  let crea = if crea#is_dead then new Tama.creature 100 100 100 100 img else crea in
  ( try
    draw_loop crea (Unix.time ())
  with Exit | Graphics.Graphic_failure _ -> print_endline "BYE!" );
  Graphics.close_graph ();

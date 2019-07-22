class creature : int -> int -> int -> int -> Graphics.image ->
object
  val img : Graphics.image
  val mutable health : int
  val mutable hygiene : int
  val mutable energy : int
  val mutable happiness : int

  method private add : int -> int -> int
  method get_img : Graphics.image
  method save : unit
  method do_action : unit
  method change_selection : int -> unit
  method eat : unit
  method thunder : unit
  method bath : unit
  method kill : unit
  method sleep : unit
  method deplete : unit
  method is_dead : bool
  method draw : unit
end

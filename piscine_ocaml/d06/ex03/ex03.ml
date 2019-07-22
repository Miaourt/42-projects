module type FIXED = 
    sig
        type t
        val of_float : float -> t
        val of_int : int -> t
        val to_float : t -> float
        val to_int : t -> int 
        val to_string : t -> string
        val zero : t
        val one : t
        val succ : t -> t
        val pred : t -> t
        val min : t -> t -> t
        val max : t -> t -> t
        val gth : t -> t -> bool
        val lth : t -> t -> bool
        val gte : t -> t -> bool
        val lte : t -> t -> bool
        val eqp : t -> t -> bool
        val eqs : t -> t -> bool
        val add : t -> t -> t
        val sub : t -> t -> t
        val mul : t -> t -> t
        val div : t -> t -> t
        val foreach : t -> t -> (t -> unit) -> unit
    end

module type FRACTIONNAL_BITS =
    sig
        val bits : int
    end

module type MAKE = 
    functor (Fractionnal_bits : FRACTIONNAL_BITS) -> FIXED

module Make = functor (Fractionnal_bits : FRACTIONNAL_BITS) ->
    struct
        type t = int

        let of_float (x:float) : int = int_of_float (ceil (( x *. 2. ** (float_of_int Fractionnal_bits.bits ) )) )
        let of_int (x:int) : int = int_of_float ((float_of_int x ) *. (2. ** (float_of_int Fractionnal_bits.bits)))
        let to_float (t:t) : float = (float_of_int t /.  (2. ** float_of_int(Fractionnal_bits.bits )))
        let to_int x : int = int_of_float ((float_of_int x ) /. (2. ** (float_of_int Fractionnal_bits.bits)))
        let to_string t = string_of_float (to_float t)
        let zero : t = 0
        let one : t = of_int 1
        let succ t = of_float (to_float t +. 1.)
        let pred t = of_float (to_float t -. 1.)
        let min (a : t) (b : t) = if (to_float a) > (to_float b) then b else a
        let max (a : t) (b : t) = if (to_float a) < (to_float b) then b else a
        let gth (a : t) (b : t) = if (to_float a) > (to_float b) then true else false
        let lth (a : t) (b : t) = if (to_float a) < (to_float b) then true else false
        let gte (a : t) (b : t) = if (to_float a) >= (to_float b) then true else false
        let lte (a : t) (b : t) = if (to_float a) <= (to_float b) then true else false
        let eqp (a : t) (b : t) = if (to_float a) == (to_float b) then true else false
        let eqs (a : t) (b : t) = if (to_float a) = (to_float b) then true else false
        let add (a : t) (b : t) = of_float ((to_float a) +. (to_float b))
        let sub (a : t) (b : t) = of_float ((to_float a) -. (to_float b))
        let mul (a : t) (b : t) = of_float ((to_float a) *. (to_float b))
        let div (a : t) (b : t) = of_float ((to_float a) /. (to_float b))
        let foreach (a : t) (b : t) (f : t -> unit) = 
            let rec runner value goal =
              (f value);
              if (value < goal) then runner (value + 1) goal
            in
            runner a b
    end

module Fixed4 : FIXED = Make (struct let bits = 4 end)
module Fixed8 : FIXED = Make (struct let bits = 8 end)

let () =
    let x8 = Fixed8.of_float 21.10 in
    let y8 = Fixed8.of_float 21.32 in
    let r8 = Fixed8.add x8 y8 in

    print_endline (Fixed8.to_string x8) ; print_char '\n';
    print_endline (Fixed8.to_string y8);
    print_endline (Fixed8.to_string r8);
    print_endline "DEBUT";
    Fixed8.foreach (Fixed8.one) (Fixed8.of_int 2) (fun f -> print_endline (Fixed8.to_string f));
    print_endline "FIN";

    let x8 = Fixed8.of_int 21 in
    let y8 = Fixed8.of_int 21 in
    let r8 = Fixed8.add x8 y8 in

    print_endline (Fixed8.to_string x8) ; print_char '\n';
    print_endline (Fixed8.to_string y8);
    print_endline (Fixed8.to_string r8);
    print_endline (string_of_float (Fixed8.to_float Fixed8.one))
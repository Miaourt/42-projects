let sum x y = x +. y

let () =
    print_endline ("42.42 + 21.21 = " ^ string_of_float (sum 42.42 21.21))
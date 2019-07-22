let rec ft_sum f min max =
    let rec runner i acc =
        if i > max then acc
        else runner (i + 1) (f i +. acc)
    in
    if min > max then nan
    else runner min 0.0


let tests () =
	print_endline ("Test with (fun i -> float_of_int (i * i)) 1 10 : " ^ string_of_float (ft_sum (fun i -> float_of_int (i * i)) 1 10));
	print_endline ("Test with (fun i -> float_of_int (i * i)) 1 5 : " ^ string_of_float (ft_sum (fun i -> float_of_int (i * i)) 1 5))

let () = tests ()
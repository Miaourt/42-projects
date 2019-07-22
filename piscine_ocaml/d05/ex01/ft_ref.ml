type 'a ft_ref = { mutable content : 'a }

let return ftref = { content = ftref }
let get ftref = ftref.content
let set ftref newContent = ftref.content <- newContent
let bind ftref (f : 'a -> 'b ft_ref) = f (get ftref)

let () =
    let value = return 42
    in
    let str = return "lambda"
    in
    let value2 = bind value (fun x -> return (x * 2))
    in
    print_string "Value = ";
    print_int (get value); print_char '\n';
    print_string "Value2 = ";
    print_int (get value2); print_char '\n';
    print_string "Str = ";
    print_endline (get str);
    print_string "Str after changement = ";
    set str "gamma";
    print_endline (get str);
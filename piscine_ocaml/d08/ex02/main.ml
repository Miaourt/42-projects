let () =
    let m = new Alkane.methane in
    print_endline (m#to_string);
    let e = new Alkane.ethane in
    print_endline (e#to_string);
    let o = new Alkane.octane in
    print_endline (o#to_string)
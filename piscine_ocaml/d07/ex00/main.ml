let () =
    let boulet = new People.people "Boulet" in
    print_endline boulet#to_string;
    boulet#talk;
    boulet#die
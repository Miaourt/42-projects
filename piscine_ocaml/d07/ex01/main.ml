let () =
    let boulet = new People.people "Boulet" in
    print_endline boulet#to_string;
    boulet#talk;
    boulet#die;
    let doctor = new Doctor.doctor "Rick" 69 boulet in
    print_endline doctor#to_string;
    doctor#talk;
    doctor#travel_in_time 100 400;
    doctor#hurt;
    print_endline doctor#to_string;
    doctor#use_sonic_screwdriver;
    doctor#regenerate;
    print_endline doctor#to_string
let () =
    Random.self_init();
    let boulet = new People.people "Boulet" in
    let doctor = new Doctor.doctor "Rick" 69 boulet in
    let dalek01 = new Dalek.dalek in
    print_endline dalek01#to_string;
    print_endline doctor#to_string;
    print_endline boulet#to_string;
    dalek01#talk;
    doctor#use_sonic_screwdriver;
    dalek01#talk;
    dalek01#exterminate boulet;
    doctor#use_sonic_screwdriver;
    dalek01#die
let () =
    let hydrogen = new Atom.hydrogen in
    hydrogen#print_endline;
    let carbon = new Atom.carbon in
    carbon#print_endline;
    let oxygen = new Atom.oxygen in
    oxygen#print_endline;
    let nitrogen = new Atom.nitrogen in
    nitrogen#print_endline;
    let lithium = new Atom.lithium in
    lithium#print_endline;
    let potassium = new Atom.potassium in
    potassium#print_endline;
    let titanium = new Atom.titanium in
    titanium#print_endline;
    let tungsten = new Atom.tungsten in
    tungsten#print_endline;
    let rutherfordium = new Atom.rutherfordium in
    rutherfordium#print_endline;
    let ununpentium = new Atom.ununpentium in
    ununpentium#print_endline;
    print_endline "#Equals of Lithium and Nitrogen :";
    print_int (lithium#equals nitrogen); print_newline();
    print_endline "#Equals of Rutherfordium and Carbon :";
    print_int (rutherfordium#equals carbon); print_newline();

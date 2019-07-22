class trinitrotoluene =
    object
        inherit Molecule.molecule "Trinitrotoluene" [(new Atom.nitrogen); (new Atom.nitrogen); (new Atom.nitrogen); (new Atom.hydrogen); (new Atom.hydrogen); (new Atom.hydrogen); (new Atom.hydrogen); (new Atom.hydrogen); (new Atom.oxygen); (new Atom.oxygen); (new Atom.oxygen); (new Atom.oxygen); (new Atom.oxygen); (new Atom.oxygen); (new Atom.carbon); (new Atom.carbon); (new Atom.carbon); (new Atom.carbon); (new Atom.carbon); (new Atom.carbon); (new Atom.carbon)]
    end

class water =
    object
        inherit Molecule.molecule "Water" [(new Atom.hydrogen); (new Atom.oxygen); (new Atom.hydrogen);]
    end

class carbon_dioxyde =
    object
        inherit Molecule.molecule "Carbon Dioxyde" [(new Atom.oxygen); (new Atom.oxygen); (new Atom.carbon);]
    end

class carbon_monoxide =
    object
        inherit Molecule.molecule "Carbon Monoxyde" [(new Atom.oxygen); (new Atom.carbon);]
    end

class methylene =
    object
        inherit Molecule.molecule "Methylene" [(new Atom.hydrogen); (new Atom.hydrogen); (new Atom.carbon);]
    end

class tricarbon_monoxide =
    object
        inherit Molecule.molecule "Tricarbon Monoxide" [(new Atom.carbon); (new Atom.carbon); (new Atom.oxygen); (new Atom.carbon);]
    end

let () =
    let trinitrotoluene = new trinitrotoluene in
    print_string (trinitrotoluene#name ^ " "); print_endline (trinitrotoluene#formula);
    let water = new water in
    print_string (water#name ^ " "); print_endline (water#formula);
    let carbon_dioxyde = new carbon_dioxyde in
    print_string (carbon_dioxyde#name ^ " "); print_endline (carbon_dioxyde#formula);
    let carbon_monoxide = new carbon_monoxide in
    print_string (carbon_monoxide#name ^ " "); print_endline (carbon_monoxide#formula);
    let methylene = new methylene in
    print_string (methylene#name ^ " "); print_endline (methylene#formula);
    let tricarbon_monoxide = new tricarbon_monoxide in
    print_string (tricarbon_monoxide#name ^ " "); print_endline (tricarbon_monoxide#formula)

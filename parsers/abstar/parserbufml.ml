(* val line : string;; *)
let line = Pervasives.read_line ();;

(* val needs_b : bool Pervasives.ref;; *)
let needs_b = Pervasives.ref false;;

String.iter (fun ch ->
  match ch, !needs_b with
  | 'a', false -> needs_b := true; ()
  | 'b', true  -> needs_b := false; ()
  | _, _       -> Pervasives.exit 1)
  line;;

Pervasives.exit 0;;

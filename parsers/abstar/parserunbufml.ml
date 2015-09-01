(* val line : string;; *)
let needs_b = Pervasives.ref false;;

try while true do (
  match input_char stdin, !needs_b with
  | 'a', false -> needs_b := true; ()
  | 'b', true  -> needs_b := false; ()
  | _, _       -> Pervasives.exit 1
) done
with End_of_file -> Pervasives.exit (if !needs_b then 1 else 0);;

let line = Pervasives.read_line ();;

(* val needs_b : bool Pervasives.ref;; *)
String.iter (fun ch ->
  match ch, !needs_b with
  | 'a', false -> needs_b := true; ()
  | 'b', true  -> needs_b := false; ()
  | _, _       -> Pervasives.exit 1)
  line;;

Pervasives.exit 0;;

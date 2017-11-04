type remoteData('e, 'a) =
  | NotAsked
  | Loading
  | Failure('e)
  | Success('a);

let map: ('a => 'b, remoteData('e, 'a)) => remoteData('e, 'b);

let map2: (('a, 'b) => 'c, remoteData('e, 'a), remoteData('e, 'b)) => remoteData('e, 'c);

let map3:
  (('a, 'b, 'c) => 'd, remoteData('e, 'a), remoteData('e, 'b), remoteData('e, 'c)) =>
  remoteData('e, 'd);

let mapError: ('e => 'f, remoteData('e, 'a)) => remoteData('f, 'a);

let mapBoth: ('a => 'b, 'e => 'f, remoteData('e, 'a)) => remoteData('f, 'b);

let andThen: ('a => remoteData('e, 'b), remoteData('e, 'a)) => remoteData('e, 'b);

let withDefault: ('a, remoteData('e, 'a)) => 'a;

let toOption: remoteData('e, 'a) => option('a);

let fromOption: (option('a), 'e) => remoteData('e, 'a);

let append: (remoteData('e, 'a), remoteData('e, 'b)) => remoteData('e, ('a, 'b));

let andMap: (remoteData('e, 'a), remoteData('e, ('a => 'b))) => remoteData('e, 'b);

let succeed: 'a => remoteData('e, 'a);

let isSuccess: remoteData('e, 'a) => bool;

let isFailure: remoteData('e, 'a) => bool;

let isLoading: remoteData('e, 'a) => bool;

let isNotAsked: remoteData('e, 'a) => bool;

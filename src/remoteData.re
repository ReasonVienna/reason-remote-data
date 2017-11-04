/*
  remote-data ported to ReasonML

  See also https://github.com/krisajenkins/remotedata
  Tools for fetching data from remote sources (incl. HTTP).
 */
type remoteData('e, 'a) =
  | NotAsked
  | Loading
  | Failure('e)
  | Success('a);

let map = (f, data) =>
  switch data {
  | Success(d) => Success(f(d))
  | Failure(error) => Failure(error)
  | NotAsked => NotAsked
  | Loading => Loading
  };

let andMap = (wrappedValue, wrappedFunction) =>
  switch wrappedFunction {
  | Success(f) => map(f, wrappedValue)
  | Failure(error) => Failure(error)
  | Loading => Loading
  | NotAsked => NotAsked
  };

let map2 = (f, a, b) => map(f, a) |> andMap(b);

let map3 = (f, a, b, c) => map(f, a) |> andMap(b) |> andMap(c);

let mapError = (f, data) =>
  switch data {
  | Success(x) => Success(x)
  | Failure(e) => Failure(f(e))
  | Loading => Loading
  | NotAsked => NotAsked
  };

let mapBoth = (successFn, failureFn, data) =>
  switch data {
  | Success(x) => Success(successFn(x))
  | Failure(e) => Failure(failureFn(e))
  | Loading => Loading
  | NotAsked => NotAsked
  };

let andThen = (f, data) =>
  switch data {
  | Success(a) => f(a)
  | Failure(e) => Failure(e)
  | Loading => Loading
  | NotAsked => NotAsked
  };

let withDefault = (default, data) =>
  switch data {
  | Success(a) => a
  | _ => default
  };

let toOption = (data) => data |> map((a) => Some(a)) |> withDefault(None);

let fromOption = (option, errorMsg) =>
  switch option {
  | Some(a) => Success(a)
  | None => Failure(errorMsg)
  };

let append = (a, b) => map((x, y) => (x, y), a) |> andMap(b);

let succeed = (a) => Success(a);

let isSuccess = (data) =>
  switch data {
  | Success(_a) => true
  | _ => false
  };

let isFailure = (data) =>
  switch data {
  | Failure(_e) => true
  | _ => false
  };

let isLoading = (data) =>
  switch data {
  | Loading => true
  | _ => false
  };

let isNotAsked = (data) =>
  switch data {
  | NotAsked => true
  | _ => false
  };

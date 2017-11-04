type data;

type remoteData = RemoteData.remoteData(string, data);

type action =
  | Noop;

type props = {
  fetch: unit => Js.Promise.t(data),
  renderLoading: unit => ReasonReact.reactElement,
  renderError: string => ReasonReact.reactElement,
  renderSuccess: data => ReasonReact.reactElement,
  renderNotAsked: unit => ReasonReact.reactElement
};

type state = {data: remoteData};

let component = ReasonReact.reducerComponent("Loader");

let make =
    (
      ~fetch,
      ~renderError,
      ~renderLoading,
      ~renderSuccess,
      ~renderNotAsked,
      ~renderLoading,
      _children
    ) => {
  ...component,
  initialState: () => {data: NotAsked},
  reducer: (action, _state) =>
    switch action {
    | Noop => ReasonReact.NoUpdate
    },
  render: (self) =>
    switch self.state.data {
    | NotAsked => renderNotAsked()
    | Failure(err) => renderError(err)
    | Success(d) => renderSuccess(d)
    | Loading => renderLoading()
    }
};

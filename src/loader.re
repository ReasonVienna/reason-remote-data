type data = string;

type remoteData = RemoteData.remoteData(string, data);

type action =
  | Load
  | UpdateError(string)
  | UpdateData(data);

type props = {
  fetch: unit => Js.Promise.t(data),
  renderNotAsked: unit => ReasonReact.reactElement,
  renderError: string => ReasonReact.reactElement,
  renderSuccess: data => ReasonReact.reactElement
};

type state = {data: remoteData};

let component = ReasonReact.reducerComponent("Loader");

type renderView = ReasonReact.reactElement => ReasonReact.reactElement;

let make =
    (
      ~fetch,
      ~renderError,
      ~renderSuccess,
      ~renderNotAsked,
      ~renderLoading,
      children
    ) => {
  ...component,
  initialState: () => {data: NotAsked},
  reducer: (action, _state) =>
    switch action {
    | Load => ReasonReact.Update({data: Loading})
    | UpdateError(errorMsg) => ReasonReact.Update({data: Failure(errorMsg)})
    | UpdateData(data) => ReasonReact.Update({data: Success(data)})
    },
  render: (self) => {
    let loadData = () => {
      fetch()
      |> Js.Promise.then_(
           (data) => {
             self.reduce(() => UpdateData(data), ());
             Js.Promise.resolve()
           }
         )
      |> ignore;
      ()
    };
    let view =
      switch self.state.data {
      | NotAsked => renderNotAsked()
      | Failure(err) => renderError(err)
      | Success(d) => renderSuccess(d)
      | Loading => renderLoading()
      };
    let renderView = children[0];
    renderView(view, loadData)
  }
};

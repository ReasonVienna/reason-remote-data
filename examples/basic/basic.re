let fakeFetch = () => Js.Promise.(resolve("fetched some some data!"));

let renderError = (err) =>
  <div> (ReasonReact.stringToElement("Error: " ++ err)) </div>;

let renderNotAsked = () =>
  <div> (ReasonReact.stringToElement("Nothing.")) </div>;

let renderLoading = () =>
  <div> (ReasonReact.stringToElement("Loading...")) </div>;

let renderSuccess = (data) =>
  <div> (ReasonReact.stringToElement("data has been loaded: " ++ data)) </div>;

let myLoader =
  <Loader
    fetch=fakeFetch renderNotAsked renderError renderLoading renderSuccess>
    (
      (view, loadData) =>
        <div>
          <button onClick=((_event) => loadData())>
            (ReasonReact.stringToElement("Click"))
          </button>
          view
          (ReasonReact.stringToElement("test."))
        </div>
    )
  </Loader>;

ReactDOMRe.renderToElementWithId(myLoader, "index");

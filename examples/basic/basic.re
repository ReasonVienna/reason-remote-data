let se = ReasonReact.stringToElement;

let fakeFetch = () => Js.Promise.(resolve("fetched some some data!"));

let renderError = (err) => <div> (se("Error: " ++ err)) </div>;

let renderNotAsked = () => <div> (se("Nothing.")) </div>;

let renderLoading = () => <div> (se("Loading...")) </div>;

let renderSuccess = (data) =>
  <div> (se("data has been loaded: " ++ data)) </div>;

let myLoader =
  <Loader
    fetch=fakeFetch renderNotAsked renderError renderLoading renderSuccess>
    (
      (view, loadData) =>
        <div>
          view
          <button onClick=((_event) => loadData())> (se("Click")) </button>
        </div>
    )
  </Loader>;

ReactDOMRe.renderToElementWithId(myLoader, "index");

let fakeFetch = () => "";

let renderError = (err) => <div> ReasonReact.stringToElement ("Error: " ++ err) </div>;

let myLoader = <Loader fetch=fakeFetch renderError />;

ReactDOMRe.renderToElementWithId(myLoader, "index");

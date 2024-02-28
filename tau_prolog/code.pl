:- use_module(library(js)).
:- use_module(library(dom)).

    alert(Text) :-
        prop(alert, Alert),
        apply(Alert, [Text], _).

    test_alert :-
        alert('Hello, Tau Prolog! From Khomichenko Danylo').

    test_dom_editing :-
        create(div, Div),
        html(Div, '
            <h2>Some header</h2> 
            <div class="some-container"> Black background white text  </div>
            '),
        get_by_id('app', Parent),
        append_child(Parent, Div).
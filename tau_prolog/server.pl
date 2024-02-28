:- use_module(library(http/thread_httpd)).
:- use_module(library(http/http_dispatch)).
:- use_module(library(http/http_files)).

:- http_handler(root(.), http_reply_from_files('.', []), [prefix]).

server(Port) :-
    http_server(http_dispatch, [port(Port)]).

serve :-
    server(8888).
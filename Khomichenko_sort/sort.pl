random_list(0, []).
random_list(N, [X|Xs]) :-
    random_between(1, 100, X),
    N1 is N - 1,
    random_list(N1, Xs).

binary_heaps(List, Heaps) :-
    binary_heaps(List, 0, Heaps).

binary_heaps([], _, []).
binary_heaps([X|Xs], Index, [heap(Index, X)|Heaps]) :-
    Index1 is Index + 1,
    binary_heaps(Xs, Index1, Heaps).

get_value(Index, Heaps, Value) :-
    nth0(Index, Heaps, heap(_, Value)).

get_values([], _, []).
get_values([Index|Indexes], Heaps, [Value|Values]) :-
    get_value(Index, Heaps, Value),
    get_values(Indexes, Heaps, Values).

get_indexes([], []).
get_indexes([heap(Index, _)|Heaps], [Index|Indexes]) :-
    get_indexes(Heaps, Indexes).

compare_heaps_index(Index1, Index2, Heaps) :-
    get_value(Index1, Heaps, Value1),
    get_value(Index2, Heaps, Value2),
    Value1 =< Value2.

sort_heaps(Indexes, Heaps, SortedIndexes) :-
    quicksort(Indexes, Heaps, SortedIndexes).

quicksort([], _, []).
quicksort([Index|Indexes], Heaps, SortedIndexes) :-
    partition(Indexes, Index, Heaps, Less, Greater),
    quicksort(Less, Heaps, SortedLess),
    quicksort(Greater, Heaps, SortedGreater),
    append(SortedLess, [Index|SortedGreater], SortedIndexes).

partition([], _, _, [], []).
partition([Index|Indexes], Pivot, Heaps, [Index|Less], Greater) :-
    compare_heaps_index(Index, Pivot, Heaps),
    partition(Indexes, Pivot, Heaps, Less, Greater).

partition([Index|Indexes], Pivot, Heaps, Less, [Index|Greater]) :-
    \+ compare_heaps_index(Index, Pivot, Heaps),
    partition(Indexes, Pivot, Heaps, Less, Greater).





quicksort_list([X|Xs],Ys) :-
    partition_list(Xs,X,Left,Right),
    quicksort_list(Left,Ls),
    quicksort_list(Right,Rs),
    append_list(Ls,[X|Rs],Ys).
quicksort_list([],[]).

partition_list([X|Xs],Y,[X|Ls],Rs) :-
    X <= Y, partition_list(Xs,Y,Ls,Rs).
partition_list([X|Xs],Y,Ls,[X|Rs]) :-
    X > Y, partition_list(Xs,Y,Ls,Rs).
partition_list([],Y,[],[]).

append_list([],Ys,Ys).
append_list([X|Xs],Ys,[X|Zs]) :- append_list(Xs,Ys,Zs).



test(N, RandomList, SortedIndexes, ListWithHeaps, SortedValues, SorderList) :-
    random_list(N, RandomList),
    binary_heaps(RandomList, ListWithHeaps),
    get_indexes(ListWithHeaps, Indexes),
    sort_heaps(Indexes, ListWithHeaps, SortedIndexes),
    get_values(SortedIndexes, ListWithHeaps, SortedValues).
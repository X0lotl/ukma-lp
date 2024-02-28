data LinkedList a = Empty | Node a (LinkedList a)

displayList :: Show a => LinkedList a -> IO ()
displayList Empty = putStrLn "Empty"
displayList (Node x xs) = do
  putStr (show x ++ " -> ")
  displayList xs

quickSortList :: Ord a => LinkedList a -> LinkedList a
quickSortList Empty = Empty
quickSortList (Node x xs) =
  let smallerSorted = quickSortList (filter (<= x) xs)
      biggerSorted = quickSortList (filter (> x) xs)
  in append smallerSorted (Node x biggerSorted)
  where
    filter _ Empty = Empty
    filter p (Node y ys)
      | p y = Node y (filter p ys)
      | otherwise = filter p ys

append :: LinkedList a -> LinkedList a -> LinkedList a
append Empty ys = ys
append (Node x xs) ys = Node x (append xs ys)


data DoubleLinkedList a = DEmpty | DNode a (DoubleLinkedList a) (DoubleLinkedList a)

displayDList :: Show a => DoubleLinkedList a -> IO ()
displayDList DEmpty = putStrLn "Empty"
displayDList (DNode x xs _) = do
  putStr (show x ++ " -> ")
  displayDList xs


quickSortDList :: Ord a => DoubleLinkedList a -> DoubleLinkedList a
quickSortDList DEmpty = DEmpty
quickSortDList (DNode x xs _) =
  let smallerSorted = quickSortDList (filterDList (<= x) xs)
      biggerSorted = quickSortDList (filterDList (> x) xs)
  in appendDList smallerSorted (DNode x biggerSorted DEmpty)
  where
    filterDList _ DEmpty = DEmpty
    filterDList p (DNode y ys _) 
      | p y = DNode y (filterDList p ys) DEmpty
      | otherwise = filterDList p ys

appendDList :: DoubleLinkedList a -> DoubleLinkedList a -> DoubleLinkedList a
appendDList DEmpty ys = ys
appendDList (DNode x xs xe) ys = DNode x (appendDList xs ys) xe



list = foldr Node Empty [11, 13, 24, 77, 7, 94, 2, 85, 50, 17, 5]

sortedList = quickSortList list

dlist = foldr (\x acc -> DNode x acc DEmpty) DEmpty [11, 13, 24, 77, 7, 94, 2, 85, 50, 17, 5]

sortedDList = quickSortDList dlist
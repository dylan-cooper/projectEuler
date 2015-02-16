import Data.List

factorials :: [Integer]
factorials = [product [1..n] | n <-[0..]]

choose :: Int -> Int -> Integer
choose n r = (factorials !! n) `div` ((factorials !! r)*(factorials !! (n-r)))

listCombos :: [Integer]
listCombos = 1 : [a `choose` b | a <- [2..], b <- [1..(a `div` 2)]]

fiftyFirstRow :: [Integer]
fiftyFirstRow = take 626 listCombos

squareFree :: Integer -> Bool
squareFree x = length [n | n <- [2..root], x `mod` (n^2) == 0] == 0
    where
        root = ceiling(sqrt(sqrt(fromIntegral(x)))) + 100

uniqueCombos :: [Integer]
uniqueCombos = nub (fiftyFirstRow)

squareFreeCombos :: [Integer]
squareFreeCombos = [a | a <- uniqueCombos, squareFree a]

result :: Integer
result = sum squareFreeCombos

main = do print result


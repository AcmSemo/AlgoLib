def bubbleSort(array)
  length = array.length - 1
  
  for i in 0..length do
   for j in 1..length do
     if (array[j-1] > array[j])
       swap = array[j]
       array[j] = array[j-1]
       array[j-1] = swap
     end
   end 
  end
end

# Test
array = Array.new

array << 12
array << 1
array << 7
array << 4
array << 0
array << 18
array << -3

for element in array
  print element
  print " "
end

bubbleSort(array)

print "\nOrdered array:\n"

for element in array
  print element
  print " "
end

def selectionSort(array)
  length = array.length - 1
  
  for i in 0..(length-1) do
    pos = i
    
    for j in (i+1)..length do
     if (array[j] < array[pos])
       pos = j       
     end
    end 
    
    if pos != i
      swap = array[pos]
      array[pos] = array[i]
      array[i] = swap
    end 
  end
end

# Test
array = Array.new

array << 7
array << 1
array << 7
array << 5
array << 0
array << -8
array << -3

for element in array
  print element
  print " "
end
print "\n"

selectionSort(array)

print "\nOrdered array:\n"

for element in array
  print element
  print " "
end
def binarySearch(array, low, high, element)
  if (low == high)
    if (array.at(low) == element)
      return low
    else
      return -1
    end 
  end
  
  mid = (high + low) / 2
  
  if (array.at(mid) == element)
    return mid
  elsif (array.at(mid) > element)
    return binarySearch(array, low, mid, element)
  else 
    return binarySearch(array, mid+1, high, element)
  end
end 


# Test
array = Array.new

array << 1
array << 5
array << 7
array << 9
array << 11
array << 18

pos = binarySearch(array, 0, array.length, 18) 
  
if (pos != -1)
  print("Found at position " + pos.to_s)
else
  print("Not found")
end



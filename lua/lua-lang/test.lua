
tab1 = { key1 = "val1", key2 = "val2", "val3" }
for k, v in pairs(tab1) do
	    print(k .. " - " .. v)
	end
	 
tab1.key1 = nil
for k, v in pairs(tab1) do
	    print(k .. " - " .. v)
	end

a3 = {}
for i = 1, 10 do
	    a3[i] = i
	end
for i = 1, 10 do
	print (i, a3[i])
end


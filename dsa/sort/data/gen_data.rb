


def gen_data size
  file_name = "data_#{size}.txt"

  File.open(file_name, 'w') do |f|
    size.times do |i|
      f.puts (Random.rand(100000))
    end
  end
end



8.times do |i|
  puts "Generating size: #{10 ** i}"
  gen_data 10 ** i
end

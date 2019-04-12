


def gen_data size
  file_name = "data_#{size}.txt"

  list = []
  File.open(file_name, 'w') do |f|
    size.times do |i|
      list[i] = Random.rand(size * 10)
    end

    list.sort!

    list.each do |e|
      f.puts e
    end
  end
end



8.times do |i|
  puts "Generating size: #{10 ** i}"
  gen_data 10 ** i
end

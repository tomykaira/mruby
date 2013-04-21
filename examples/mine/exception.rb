# from http://www.dzeta.jp/~junjis/code_reading/index.php?mruby%2F%CE%E3%B3%B0%BD%E8%CD%FD%A4%F2%C6%C9%A4%E0

def exc_func
  begin
    raise "Exception"
  ensure
    puts "ensure in exc_func"
  end
end

begin
  exc_func
rescue => e
  puts "rescue in top"
  puts e.message
rescue Exception, TimeoutError => e
  puts "all"
else
  puts "else"
ensure
  puts "ensure in top"
end

begin
  begin
    begin
      raise "e1"
    rescue
      raise "e2"
    end
  rescue
    raise "e3"
  end
rescue
  raise "e4"
end

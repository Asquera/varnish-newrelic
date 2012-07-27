require 'rubygems'
require 'sinatra'

get '/' do
  if request["X-Request-Start"]
    request_start = request["X-Request-Start"]
    "X-Request-Start: #{request_start}"
  else
    "No X-Request-Start found"
  end
end


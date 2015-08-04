package Leap;

use Carp;
use warnings;
use strict;


use vars qw($VERSION @ISA @EXPORT @EXPORT_OK %EXPORT_TAGS);

$VERSION     = 1.00;
@ISA         = qw(Exporter);
@EXPORT      = ();
@EXPORT_OK   = qw(hey);
%EXPORT_TAGS = ( DEFAULT => [qw(&is_leap)],);


sub is_leap($) {
    my $year = shift(@_);
    if ($year =~ m/^\s*(\d\d\d\d)\s*$/) {
        #on every year that is evenly divisible by 4
        #  except every year that is evenly divisible by 100
        #    unless the year is also evenly divisible by 400
        if (
            ($year % 4 == 0) &&
            (($year % 100 != 0) || (($year % 100 == 0) && ($year % 400 == 0)))
            ) {
            return 1;
        }
        return 0;
    }
    else {
        croak("Illegal year $year!\n");
    }
}

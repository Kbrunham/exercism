package ETL;

use Carp;
use warnings;
use strict;
use Exporter;
use vars qw($VERSION @ISA @EXPORT @EXPORT_OK %EXPORT_TAGS);

$VERSION     = 1.00;
@ISA         = qw(Exporter);
@EXPORT      = ();
@EXPORT_OK   = qw(
    transform
);
%EXPORT_TAGS = ( DEFAULT => [qw(
    &transform
)],);


sub transform($) {
    my $old_data = shift(@_);
    my $new_data = {};

#        old      : { 1 => ['A', 'E'], 2 => ['D', 'G'] },
#        expected : { a => 1, e => 1, d => 2, g => 2 },

    
    # Iterate over all scores in the old data;
    foreach my $score (keys(%$old_data)) {
        my $letters = $$old_data{$score};
        # Iterate over all letters in the old data
        foreach my $letter (@$letters) {
            my $lc_letter = lc($letter);
            # add the new data to the hash
            $$new_data{$lc_letter} = $score;
        }
    }
    
    return $new_data;
}